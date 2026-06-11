#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
 
int main(){
    int n;
    cin>>n;
 
    vector<int> h(n);
    bool judge=true;
    REP(i,n){
        cin>>h[i];
        if(i>0){
            if(h[i-1]==h[i]+1){
                h[i]++;
            }else if(h[i-1]>h[i]+1){
                judge=false;
                break;
            }
        }
    }
 
    cout<<(judge ? "Yes" : "No")<<endl;
}
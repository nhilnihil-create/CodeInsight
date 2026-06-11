#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n;
    string s;
    int t;
    string x;
    cin>>n;
    int tt=0;
    int st=0;
    bool sleep=0;
    vector<string>v(n);
    vector<int>vs(n);
    for(int i=0; i<n; i++){
        cin>>v.at(i)>>t;
        vs.at(i)=t;
        tt += t;
    }
    cin>>x;
    for(int j=0; j<n; j++){
        if(v.at(j)==x){
            sleep = 1;
            for(int k=j+1; k<n; k++){
                st += vs.at(k);
            }
            break;
        }
    }
    cout<<st<<endl;
}

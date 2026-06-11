#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    if(n<3) {cout<<"0";return 0;}
    int cnt=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            if(a[i]!=a[j]){
                for(int k=j+1;k<n;k++){
                    if(a[k]!=a[j] && a[k]!=a[i]){
                        set<int>s;
                        s.insert(a[i]);
                        s.insert(a[j]);
                        s.insert(a[k]);
                        set<int> ::iterator k;
                        k=s.begin();
                        if(*k++ + *k++ > *k){
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
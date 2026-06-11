#include<bits/stdc++.h>
using namespace std;
#define    for0(i,n) for(int i=0;i<n;i++)
#define    fors(i,s) for(int i=0;i<s.size();i++)
#define    nl     "\n"
#define    End    return 0
#define    gt     greater<int>()
#define    ll     long long int

int main()
{
    bool f=false;
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=a;i<=b;i++){
        if(i%n==0){
            f=true;
            break;
        }
    }
    if(f)cout<<"OK";
    else cout<<"NG";
}

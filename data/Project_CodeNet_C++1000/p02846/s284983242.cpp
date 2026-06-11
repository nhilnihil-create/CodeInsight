/*
 *  Author : Jun_SH
 *  Solution for sumitrust2019 146 F
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t1,t2,a1,a2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    if(t1*a1+t2*a2==t1*b1+t2*b2)
        puts("infinity");
    else{
        int ans=0;
        if(a1>b1){
            if(a2>=b2)ans=0;
            else {
                int tot=(t1*b1+t2*b2)-(t1*a1+t2*a2);
                int tmp=a1*t1-b1*t1;
                ans+=tmp/tot;
                ans+=(tmp-1)/tot+1;
                if(tot<0)ans=0;
            }
        }
        else if(b1>a1){
            if(b2>=a2)ans=0;
            else {
                int tot=(t1*a1+t2*a2)-(t1*b1+t2*b2);
                int tmp=b1*t1-a1*t1;
                ans+=tmp/tot;
                ans+=(tmp-1)/tot+1;
                if(tot<0)ans=0;
            }
        }
        else ans=t1;
        cout<<ans<<endl;
    }
}

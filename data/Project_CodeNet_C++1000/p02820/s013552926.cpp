#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1e5+8;
char a[N];
int main()
{
    int n,k;
    int r,s,p;
    cin>>n>>k;
    cin>>r>>s>>p;
    string t;
    cin>>t;
    int sum=0;
    for(int i=0;i<k;i++){
        if(t[i]=='r'){
            a[i]='p';
            sum+=p;
        }
        if(t[i]=='p'){
            a[i]='s';
            sum+=s;
        }
        if(t[i]=='s'){
            a[i]='r';
            sum+=r;
        }
    }
    for(int i=k;i<n;i++){
        if(t[i]=='r'){
                if(a[i-k]!='p'){
                    sum+=p;
                    a[i]='p';
                }
        }
        if(t[i]=='p'){
                if(a[i-k]!='s'){
                    sum+=s;
                    a[i]='s';
                }
        }
        if(t[i]=='s'){
                if(a[i-k]!='r'){
                    sum+=r;
                    a[i]='r';
                }
        }
    }
    cout<<sum;
}

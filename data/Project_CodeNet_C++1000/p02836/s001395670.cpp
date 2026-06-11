#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1;

int main()
{

    string s;
    cin>>s;
    int ans=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i] != s[n-1-i]){
            ans++;
            s[i]=s[n-1-i];
        }
    }
    printf("%d",ans);
    }

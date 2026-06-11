#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int main()
{
    ll n,i,j,k=0;
    cin>>n;
    string s;
    cin>>s;
    if(n%2){cout<<"No"<<endl;}
    else{
            j=s.size()/2;
        for(i=0;i<j;i++)
        {
            if(s[i]==s[i+j]) k++;
        }
    if(k==j){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
    }
    return 0;
}

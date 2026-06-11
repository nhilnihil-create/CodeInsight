#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#include<cmath>
#include<iomanip>
#include<queue>
#include<string>
using namespace std;

const double PI  =3.141592653589793238463;
#define pb push_back
#define pf push_front
#define sz(v)  ((int)(v).size());
#define all(v) ((v).begin()),((v).end())
typedef unsigned long long ull;
typedef long long ll;

typedef vector<int> vi;
typedef pair<int,int> pi;
//2 7 3 4 9

void printVec(vi v1)
{
    for(int i=0; i<v1.size(); i++)
        cout<<v1[i]<<" ";
    cout<<endl;
}
ll rec(ll r,ll c){

if(r<=1 || c<=1){
    return 1;
}


return rec(r-1,c)+rec(r,c-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
ull n;cin>>n;
string str="";
while(n>=1){
    n--;
    str+='a'+(n%26);
    n/=26;
}reverse(str.begin(),str.end());
 cout<<str;
    return 0;
}

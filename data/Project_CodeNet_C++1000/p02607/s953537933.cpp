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
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);


 int n;cin>>n;
 int a;
 int cnt=0;
 for(int i=1;i<=n;i++){
    cin>>a;
    if(a%2!=0 && i%2!=0){
cnt++;
    }
 }

 cout<<cnt<<endl;
    return 0;

}

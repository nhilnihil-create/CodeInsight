
#include<bits/stdc++.h>
#define fr(i,j,n)   for(int i=j;i<n;i++)
#define pb          push_back
#define rf(i,j,p)   for(int i=p;i>=j;i--)
#define vi          vector<int>
#define vll         vector<long long>
#define ll          long long
#define hmm         "\n"
#define sp          " "
#define srt(v)      sort(v.begin(), v.end());
#define down        cout<<hmm;
#define faaast      ios_base::sync_with_stdio(0);cin.tie(nullptr);
using namespace std;
int main()
{
 vector<pair<int, int>>v ;
 int n ; cin >> n ;
 fr(i,1,n+1)
 {
      int tem ;  cin >> tem ;
     v.pb({tem,i});
 }
 srt(v);
 fr(i,0,n)
 {
     cout<<v[i].second<<sp;
 }down ;
}

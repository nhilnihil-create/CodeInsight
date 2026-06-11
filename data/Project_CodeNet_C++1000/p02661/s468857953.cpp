#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define P pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int main()
{
  int N; cin >> N;
  int half = 0;
  vector<P> arr(N);
  rep(i, 0, N) cin >> arr[i].first >> arr[i].second;

  if(N % 2 == 0){
    half = N / 2 - 1;

    sort(arr.begin(), arr.end(), [](P a, P b){
      return a.first < b.first;
    });
    ll lowlimit1 = arr[half].first;
    ll lowlimit2 = arr[half + 1].first;

    sort(arr.begin(), arr.end(), [](P a, P b){
      return a.second < b.second;
    });
    ll highlimit2 = arr[half + 1].second;
    ll highlimit1 = arr[half].second;

   cout << (highlimit2 + highlimit1) - (lowlimit2 + lowlimit1) + 1 << endl;

  } else {
    half = N / 2;
    sort(arr.begin(), arr.end(), [](P a, P b){
      return a.first < b.first;
    });
    ll lowlimit1 = arr[half].first;
    sort(arr.begin() + half + 1, arr.end(), [](P a, P b){
      return a.second < b.second;
    });
    ll lowlimit2 = 0;
    if(arr[half].second < arr[half + 1].second) lowlimit2 = arr[half].second;
    else lowlimit2 = arr[half + 1].second;

    sort(arr.begin(), arr.end(), [](P a, P b){
      return a.second < b.second;
    });
    ll highlimit2 = arr[half].second;
    sort(arr.begin(), arr.begin() + half, [](P a, P b){
      return a.first < b.first;
    });
    ll highlimit1 = 0;
    if(arr[half].first < arr[half - 1].second) highlimit1 = arr[half - 1].second; 
    else highlimit1 = arr[half].first;

    cout << highlimit2 - lowlimit1 + 1 << endl;
  }

}


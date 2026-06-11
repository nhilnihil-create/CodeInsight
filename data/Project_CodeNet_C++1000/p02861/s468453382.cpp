#include <iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
#define ll long long

#define MAX 100020
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
#define ll long long

#define MAX 100020

long double calc_dist(vector<pair<long double, long double>> vec, int n, vector<int> &v){
    double dist=0;
    for(int i=1;i<n;i++){
        dist+= sqrt(pow((vec[v[i]].second-vec[v[i-1]].second),2) + pow((vec[v[i]].first-vec[v[i-1]].first),2));
    }
    return dist;
}
int main(){
int n;
cin>>n;

double sum=0;
vector<pair<long double,long double>> vec(n);
vector<int> v(n);
for(int i=0;i<n;i++){
    v[i]=i;
    cin>>vec[i].first>>vec[i].second;
}

double count=0;
  do {
      count++;
    sum+=calc_dist(vec,n,v);
  } while ( std::next_permutation(v.begin(),v.end()));

cout<<fixed<<setprecision(6)<<sum/count;

}


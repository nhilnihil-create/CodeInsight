#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    double sum=0;
    rep(i,n)sum+=(double)1/a[i];
    sum=1/sum;
    cout<<fixed<<setprecision(6)<<sum<<endl;
}

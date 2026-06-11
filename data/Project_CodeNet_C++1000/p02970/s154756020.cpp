#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int n,d;
    cin>>n>>d;
    int c=2*d+1;
    int e=(n/c);
    e+=(n%c==0)?0:1;
    cout<<e<<endl;
}

#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int p,q,r;
    cin>>p>>q>>r;

    int a=p+q;
    int b=q+r;
    int c=r+p;

    cout<<min(a,min(b,c))<<endl;
}


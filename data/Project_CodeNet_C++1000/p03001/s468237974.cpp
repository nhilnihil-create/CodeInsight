#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    ll w,h,x,y;
    cin>>w>>h>>x>>y;

    cout<<fixed<<setprecision(9)<<(double)(w*h)/2<<" ";
    double cx=(double)w/2;
    double cy=(double)h/2;
    if(cx==(double)x&&cy==(double)y){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
}

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
    string s;
    cin>>s;
    int cnt=1;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
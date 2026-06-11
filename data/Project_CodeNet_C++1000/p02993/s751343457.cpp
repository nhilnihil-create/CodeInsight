#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    string s;
    cin>>s;
    rep(i,4){
        if(s[i]==s[i+1]){
            cout<<"Bad"<<endl;
            return 0;
        }
    }
    cout<<"Good"<<endl;
    return 0;

}
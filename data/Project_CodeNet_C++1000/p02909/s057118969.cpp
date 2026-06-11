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
    if(s[0]=='S'){
        cout<<"Cloudy"<<endl;
    }else if(s[0]=='C'){
        cout<<"Rainy"<<endl;
    }else{
        cout<<"Sunny"<<endl;
    }
}

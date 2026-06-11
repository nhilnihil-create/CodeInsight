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
    int len;
    len=s.size();
    rep(i,len){
        if(i%2==0){
            if(s[i]!='R'&&s[i]!='U'&&s[i]!='D'){
                cout<<"No"<<endl;
                return 0; 
            }
        }else{
            if(s[i]!='L'&&s[i]!='U'&&s[i]!='D'){
                cout<<"No"<<endl;
                return 0; 
            }
        }
    }
    cout<<"Yes"<<endl;
}

                
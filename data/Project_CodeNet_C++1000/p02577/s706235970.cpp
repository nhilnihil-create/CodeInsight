#include<bits/stdc++.h>
using namespace std;

class Multiple{
private:
    string S;
    long long digitSum(string S){
        long long ans=0;
        for(char d: S){
            ans += (d-'0');
        }
        return ans;
    }
public:
    Multiple(){
        cin>>S;
    }
    bool solve(){
        long long ans = digitSum(S);
        return !(ans%9);
    }
    ~Multiple(){

    }
};

int main(){
    Multiple problem = Multiple();
    bool ans = problem.solve();
    if(ans) cout<<"Yes\n";
    else cout<<"No\n";
}
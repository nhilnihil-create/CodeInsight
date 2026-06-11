#include <iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
const int MOD=1000000007;
const int MAX = 1000001;

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    vector<long long> p;
    vector<string> s;
    vector<bool> ac;
    vector<long long> ac_n;
    for(int i=0;i<n;i++){
        ac.push_back(false);
        ac_n.push_back(0);
    }
    for(int i=0;i<m;i++){
        long long p_;
        string s_;
        cin >> p_;
        cin >> s_;
        if(ac[p_-1] == false){
            if(s_ == "AC"){
                ac[p_-1] = true;
            }
            else{
                ac_n[p_-1]++;
            }
        }
    } 
    long long ans_ac = 0;
    long long ans_wa = 0;
    for(int i=0;i<n;i++){
        if(ac[i]){
            ans_ac++;

            ans_wa += ac_n[i];
        }
    }
    cout << ans_ac <<" " <<  ans_wa << endl;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s;
    cin >> s;
    long int k;
    cin >> k;
    vector<long int> num;
    char u = s[0];
    num.push_back(1);
    long int count = 0;
    for (int i = 1; i < s.size(); i++){
        if (s[i] != u){
            num.push_back(1);
            count++;
            u = s[i];
        }else{
            num[count]++;
        }        
    }
    long int ans = 0;
    // rep(i, num.size()) cout << num[i] << " ";
    // cout << endl;

    if (num.size() == 1){
        ans = (num[0] * k) / 2;
    }else{
        if (s[0] == s[s.size()-1]){
            for (int i = 1; i < num.size() - 1; i++){
                ans += num[i] / 2;
            }
            ans *= k;
            ans += ((num[0] + num[num.size()-1]) / 2) * (k - 1);
            ans += (num[0] / 2) + (num[num.size()-1] / 2);
        }else{
            for (int i = 0; i < num.size(); i++){
                ans += num[i] / 2;
            }
            ans *= k;
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>

using namespace std;


int f(string s) {
    int ans = 0;
    int counter = 0;
    char cur = s[0];
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == cur) {
            counter++;
        } else {
            if(counter > 1) {
                if(counter % 2 == 0) {
                    ans += counter / 2;
                } else {
                    ans += (counter - 1) / 2;
                }
            }
            counter = 1;
            cur = s[i];
        }
    }
    if(counter > 1) {
        if(counter % 2 == 0) {
            ans += counter / 2;
        } else {
            ans += (counter - 1) / 2;
        }
    }
    return ans;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    if(s.size() == 1) {
        if(k % 2 == 0) {
            cout << k / 2 << "\n";
        } else {
            cout << (k - 1) / 2 << "\n";
        }
        return 0;
    }
    long long one = f(s);
    vector<int> alphabets(26, 0);
    for(int i = 0; i < s.size(); i++) {
        alphabets[s[i]-'a']++;
    }
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(alphabets[i] == 0) {
            cnt++;
        }
    }
    if(cnt == 25) {
        long long ans = k * s.size();
        if(ans % 2 == 0) {
            ans /= 2;
        } else {
            ans = (ans - 1) / 2;
        }
        cout << ans << "\n";
        return 0;
    }
    if(s[0] != s[s.size()-1]) {
        cout << one * k << "\n";
    } else {
        long long ans = one * k;
        long long a = 0, b = 0;
        char cur1 = s[0];
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == cur1) {
                a++;
            } else {
                break;
            }
        }
        long long ha;
        if(a % 2 == 0) {
            ha = a / 2;
        } else {
            ha = (a - 1) / 2;
        }
        char cur2 = s[s.size()-1];
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == cur2) {
                b++;
            } else {
                break;
            }
        }
        long long hb;
        if(b % 2 == 0) {
            hb = b / 2;
        } else {
            hb = (b - 1) / 2;
        }
        ans -= ha * (k - 1);
        ans -= hb * (k - 1);
        long long hh;
        if((a + b) % 2 == 0) {
            hh = (a + b) / 2;
        } else {
            hh = (a + b - 1) / 2;
        }
        ans += hh * (k - 1);
        cout << ans << "\n";
    }
    return 0;
}
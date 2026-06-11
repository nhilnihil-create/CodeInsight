/*
17/10/2017
*/
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> left, right;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'L') {
            left.push_back(i);
        }
    }
    reverse(left.begin(), left.end());
    int cnt[n] = {};
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            right.push_back(i);
            if(left.size() == 0) {
                cnt[n - 1]++;
            } else {
                if((left[0] - i) % 2 == 1) {
                    cnt[left[0] - 1]++;
                } else {
                    cnt[left[0]]++;
                }
            }
        } else {
            left.erase(left.begin(), left.begin() + 1);
            if(right.size() == 0) {
                cnt[0]++;
            } else {
                if((i - right[right.size() - 1]) % 2 == 1) {
                    cnt[right[right.size() - 1] + 1]++;
                } else {
                    cnt[right[right.size() - 1]]++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << cnt[i] << " ";
    }
}
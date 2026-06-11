#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<string> s(N);

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        sort(input.begin(), input.end());
        s[i] = input;
    }

    sort(s.begin(), s.end());

    vector<int> counts(0);
    counts.push_back(1);
    for(int i = 1; i < N; i++){
        if(s[i] != s[i-1]){
            counts.push_back(1);
        } else {
            counts[counts.size() - 1]++;
        }
    }

    ll result = 0;
    for(int i = 0; i < counts.size(); i++){
        ll val = counts[i];
        result += val * (val - 1) / 2;
    }

    cout << result << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<int> a(N);
    map<int, int> counts;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        
    }

    for(int i = 0; i < N; i++){
        counts[a[i]]++;
    }

    vector<int> keys;
    for (auto it = counts.begin(); it != counts.end(); it++)
    {
        keys.push_back(it -> first);
    }

    sort(keys.begin(), keys.end());

    int entries = keys.size();
    

    if(entries == 1){
        if(keys[0] == 0){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if(entries == 2){
        if(keys[0] == 0){
            if(counts[keys[0]] * 3 == N){
                cout << "Yes" <<endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    } else if(entries == 3){
        if(counts[keys[0]] == counts[keys[1]] && counts[keys[1]]== counts[keys[2]]){
            if((keys[0] ^ keys[1]) == keys[2]){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
    return 0;
}

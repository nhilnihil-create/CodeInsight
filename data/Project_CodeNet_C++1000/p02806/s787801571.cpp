#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<string,int> sleep[n];
    for(int i=0;i<n;i++){
        string s;
        int a;
        cin >> s >> a;
        sleep[i].first = s;
        sleep[i].second = a;
    }
    string time;
    cin >> time;
    bool flag = false;
    int count = 0;
    for(int i=0;i<n;i++){
        if(flag){
            count += sleep[i].second;
        }
        if(sleep[i].first==time) flag = true;
    }
    cout << count << endl;
}

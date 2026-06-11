#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pc __builtin_popcountll

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    int white_count = 0;
    for(int i= 0; i < n; ++i){
        if(s[i] == 'W'){
            white_count++;
        }
    }

    // No whites
    if(white_count == 0){
        cout << 0;
        return 0;
    }

    int red_count = 0;
    for(int i = n - white_count; i < n; ++i){
        if(s[i] == 'R'){
            ++red_count;
        }
    }

    cout << red_count << "\n";
    return 0;
}
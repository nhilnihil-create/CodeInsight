#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    for(int i=0; i<n; ++i)
        cin >> b[i];

    if(lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())){
        int count=0;
        do{
            if(a == b){
                cout << count;
                return 0;
            }
            count++;
        }
        while(next_permutation(a.begin(), a.end()));
    }
    else{
        int count=0;
        do{
            if(a == b){
                cout << count;
                return 0;
            }
            count++;
        }
        while(prev_permutation(a.begin(), a.end()));
    }
    return 0;
}

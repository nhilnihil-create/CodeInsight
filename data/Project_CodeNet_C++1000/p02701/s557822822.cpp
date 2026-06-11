#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int n; cin >> n;
    set<string> s;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        s.insert(str);
    }
    cout << s.size() << endl;
    return 0;
}
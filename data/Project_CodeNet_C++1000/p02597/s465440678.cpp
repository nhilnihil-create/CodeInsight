#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N;
int arr[200000];

void solve(){
    cin >> N;

    string s ;
    cin >> s;
    int i = 0;
    for (char c : s)
    {
        //cout << c << endl;
        if(c == 'R') arr[i] = 0;
        else arr[i] = 1;
        i++;
    }
    
    int l = 0;
    int r = N-1;


    
    
    int count = 0;
    while (l < r)
    {
        
        if(arr[l] == 1 && arr[r] == 0){
            count++;
            l++;
            r--;
            continue;
        }
        if(arr[l] == 0 ){
            l++;
        }
        if(arr[r] == 1){
            r--;
        }

    }
    
    cout << count << "\n";

    
}






int main(){

    //ios::sync_with_stdio(false);
    //cin.tie(0);

    solve();

}
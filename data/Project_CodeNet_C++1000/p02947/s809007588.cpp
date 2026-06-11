#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string s[100007];
int main(){
    cin >> N;
    for(int i = 0;i < N;i++) {
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
    }

    sort(s,s + N);

    long long int ans = 0;
    long long int j = 0;
    for(int i = 0;i < N-1 ;i++){
        //cout << s[i] << " と " << s[i+1] << endl;
        if(s[i] == s[i+1]){
            j++;
            ans = ans + j;
        }else{
            j = 0;
        }
    }

    cout << ans << endl;
}
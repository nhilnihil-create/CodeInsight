
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<cstdlib>



using namespace std;

int n,k,R,S,P;
int arr[100001];
int rock = 1,scissor = 2, paper = 3;
int ans=0;
string s;

int main(){
    cin >> n >> k;
    cin >> R >> S >> P ;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'r'){
            arr[i] = rock;
        }
        else if(s[i] == 's'){
            arr[i] = scissor;
        }
        else if(s[i] == 'p'){
            arr[i] = paper;
        }
    }
    
    for(int i=0;i<k;i++){
        for(int j=i;j<n;j+=k){
            if(arr[j] == rock) ans += P;
            else if(arr[j] == scissor) ans += R;
            else if(arr[j] == paper) ans += S;

            if(j+k < n){
                if(arr[j] == arr[j+k]) j += k;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
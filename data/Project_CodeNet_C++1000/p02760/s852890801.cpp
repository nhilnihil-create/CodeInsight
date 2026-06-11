#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int a[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(b==a[i][j]) a[i][j]=0;
            }
        }
    }

    for(int i=0;i<3;i++){
        if(a[i][0]==a[i][1] && a[i][2]==a[i][1]){
            cout << "Yes" << endl;
            return 0;
        }
    }

    for(int i=0;i<3;i++){
        if(a[0][i]==a[1][i] && a[2][i]==a[1][i]){
            cout << "Yes" << endl;
            return 0;
        }
    }

    if((a[0][0]==a[1][1] && a[1][1]==a[2][2]) || a[0][2]==a[1][1] && a[1][1]==a[2][0]){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}
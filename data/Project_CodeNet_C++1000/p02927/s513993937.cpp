#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,d;
    cin >> m >> d;
    int cnt = 0;
    for(int i = 4; i <= m; i++){
        for(int j = 22; j <= d; j++){
            int jd = j / 10;
            int ji = j % 10;
            if(jd >= 2 && ji >= 2 && jd * ji == i)
            cnt++;
        }
    }
    cout << cnt << endl;
}
#include <iostream>
using namespace std ;
int main(){
    int t ,r ;
    cin >> t >> r ;
    int s[r] ;
    int t2 =0;
    for(int i=0 ;i<r;i++){
        cin >> s[i];
        t2 =t2 +s[i];
    }
    if (t2>t)cout << "-1";
    else
        cout << t-t2;


    return 0;
}

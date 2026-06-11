
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : September 11, 2020 3:22 PM
 *    Problem Name  : B - Papers, Please
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/abc155/tasks/abc155_b
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n ;

    int x,cnt=0;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x%2 == 0){
            if(x%3!=0 && x%5!=0){
                cnt++;
            }
        }
    }

    if(cnt > 0) cout << "DENIED" << endl;   
    else cout << "APPROVED" << endl;

    return 0 ;
}

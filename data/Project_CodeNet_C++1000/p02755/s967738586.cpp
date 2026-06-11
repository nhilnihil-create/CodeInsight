#include <bits/stdc++.h>
using namespace std;
int main(){
    double a, b;
  	cin >> a >> b;
    int answer = -1;
    int answerbegin = (int)(a/0.08 +0.9);
    int answerend = (int)((a+1)/0.08 +0.9);
    bool br = false;
    for(int i=answerbegin; i<answerend; i++){
        for(int j=0; j<10; j++){
            if( i==(10*b+j) ){
                answer = i;
                br = true;
                break;
            }
        }
        if(br) break;
    }
    cout << answer;

}
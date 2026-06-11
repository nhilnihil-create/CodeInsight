#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string S, T;
    cin >> S >> T;
    
    int answer=1001; //1000以上にしておく
    
    for(int i=0; i<S.size()-T.size()+1; i++){
        int x=0;
        for(int j=0; j<T.size(); j++){
            if(S.at(i+j)!=T.at(j)){
                x++; //一致しなかった文字の数
            }
        }
        
        if(x<answer){
            answer = x;
        }
    }
    
    cout << answer << endl;
}
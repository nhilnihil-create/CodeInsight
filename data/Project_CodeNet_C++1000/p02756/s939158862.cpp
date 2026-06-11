#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int Qi, Fi, rev_st = 0;
    char c;
    string S, Sc;
    std::cin >> S;

    long long Q;
    std::cin >> Q;

    for(int i = 0; i < Q; i++){
        //Q回操作をする。操作内容は愚直に実装
        std::cin >> Qi;
        if(Qi == 1){
            //Ti = 1の場合、反転状態を記録
            rev_st = (rev_st + 1)%2;
        }else{
            //Ti = 2の場合、反転状態に応じて文字を追加
            std::cin >> Fi >> c;
            if(rev_st == 1){
                //反転している場合
                if(Fi == 1){
                    S.push_back(c);
                }else{
                    S.insert(S.begin(), c);
                }
            }else{
                //反転していない場合
                if(Fi == 2){
                    S.push_back(c);
                }else{
                    S.insert(S.begin(), c);
                }
            }
        }
    }
    //入力完了
    if(rev_st == 1){
        std::reverse(S.begin(), S.end());
    }

    std::cout << S;

}
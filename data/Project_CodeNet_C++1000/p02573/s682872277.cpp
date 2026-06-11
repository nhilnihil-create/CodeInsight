#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<deque>
using namespace std;

int main(){
    long long N, M;
    long long A, B;
    long long ans = 0, tmp, count, tmp_find, nextf;
    vector<long long> v_temp;
    deque<long long> friend_sagasu;
    std::cin >> N >> M;
    map<long long, vector<long long>> f_list;
    vector<long long> hito(N,0); //カウント済みがどうかを確認するようの配列
    for(long long i = 0; i < M; i++){
        std::cin >> A >> B;
        if(f_list.count(A)){
            //既にある場合
            f_list[A].push_back(B);
        }else{
            f_list[A] = {B};
        }
        //逆もやる
        if(f_list.count(B)){
            //既にある場合
            f_list[B].push_back(A);
        }else{
            f_list[B] = {A};
        }
    }
    //インプット完了
    if(M == 0){
        ans = 1;
    }else{
        std::map<long long, vector<long long>>::iterator iter = f_list.begin();
        for(int i = 0; i < f_list.size(); i++){
            //フレンドリスト順に
            tmp = iter->first;
            if(hito[tmp - 1] == 0){
                //まだ登録されていなければそいつをもとに探索開始
                friend_sagasu.push_back(tmp);
                count = 1;
                hito[tmp - 1] = 1;
                while(friend_sagasu.size()!=0){
                    tmp_find = friend_sagasu[0];
                    friend_sagasu.pop_front();
                    for(int j = 0; j < f_list[tmp_find].size(); j++){
                        //友達を追加，カウント増加，カウントフラグ建て
                        nextf = f_list[tmp_find][j];
                        if(hito[nextf - 1] == 0){
                            friend_sagasu.push_back(nextf);
                            count++;
                            hito[nextf - 1] = 1;
                        }

                    }
                }
                //グループを作り終わる
                if(count > ans){
                    ans = count;
                }
            }
            //初期化とかする
            iter++;



        }
    }
    std::cout << ans;

}

#include <iostream>
#include <cstdio>
#include <vector>
#define N 100
typedef struct SearchTime SearchTime;

struct SearchTime{
    int find = -1;
    int comp = -1;
    bool flag = false;
    void print(){
        std::cout << find << " " << comp << '\n';
    }
};

int cnt = 1;
SearchTime st[N];

void input_graph(std::vector<std::vector<int> >& Adj, int n){
    int u, k, v;
    for(int i=0; i<n; i++){
        std::cin >> u >> k;
        for(int j=0; j<k; j++){
            std::cin >> v;
            Adj[u-1].push_back(v);
        }
    }
}

void result(int n){
    for(int i=0; i<n; i++){
        std::cout << i+1 << " ";
        st[i].print();
    }
}

void DFS(std::vector<std::vector<int> >& Adj, int n){
    int i = 0;
    int j;
    int nexti;              //毎回-1する.
    std::vector<int> tmp;   //軌跡を保存
    bool newflag = false;
    //深さ優先探索
    while(cnt <= n*2){
        //下層へ探索
        //std::cout << "\nstrat\n";
        newflag = false;
        while(i != -1){
            st[i].flag = true;
            st[i].find = cnt;
            cnt++;
            //std::cout << "cnt:" << cnt-1 << '\n';
            tmp.push_back(i);
            //std::cout << "tmp.size():" << tmp.size() << '\n';
            //std::cout << "i:" << i+1 << '\n';
            //次の葉を探す
            if((int)Adj[i].size() != 0){//葉が最深でないとき
                j = 0;
                nexti = Adj[i][j]-1;
                while(st[nexti].flag){
                    j++;
                    if(j == (int)Adj[i].size()){//もし葉がすべて探索済みなら
                        st[i].comp = cnt;
                        cnt++;
                        //std::cout << "tochu\n";
                        //std::cout << "cnt:" << cnt-1 << '\n';
                        i = -1; //2つ目のwhile文抜ける
                        break;
                    }
                    nexti = Adj[i][j]-1;
                }
                if(i != -1) i = nexti;
            }
            else{//葉が最深のとき
                st[i].comp = cnt;
                cnt++;
                i = -1; //2つ目のwhile文抜ける
                //std::cout << "saishin\n";
                //std::cout << "cnt:" << cnt-1 << '\n';
                //std::cout << "tmp.size():" << tmp.size() << '\n';
                //std::cout << "i:" << i << '\n';
            }
        }
        //ここから根に向かって戻る. 未探索の葉があればそちらへ行く
        //std::cout << "\nback\n";
        tmp.pop_back();
        i = (int)tmp.back();
        tmp.pop_back();
        //std::cout << "tmp.size():" << tmp.size() << '\n';
        //std::cout << "i:" << i+1 << '\n';
        j = 0;
        nexti = Adj[i][j]-1;
        while(st[nexti].flag){
            j++;
            if(j == (int)Adj[i].size()){//現在のノードから未探索の葉がない
                if((int)tmp.size() != 0){//まだtmpに軌跡が残っていれば
                    st[i].comp = cnt;
                    cnt++;
                    //std::cout << "cnt:" << cnt-1 << '\n';
                    i = (int)tmp.back();
                    tmp.pop_back();
                    //std::cout << "tmp.size():" << tmp.size() << '\n';
                    //std::cout << "i:" << i+1 << '\n';
                    j = 0;
                    nexti = Adj[i][j]-1;
                }
                else{//残っていないなら
                    st[i].comp = cnt;
                    cnt++;      //たぶんこれで終わる
                    //std::cout << "cnt:" << cnt-1 << '\n';
                    if(cnt != n*2){//まだ未探索ノードが残ってる
                        i = 0;
                        while(st[i].flag){
                            i++;
                        }
                        newflag = true;
                    }
                    break;
                }
            }
            else{
                nexti = Adj[i][j]-1;
            }
        }
        if(!newflag){
            tmp.push_back(i);
            i = nexti;
        }
    }
}


int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > Adj;
    Adj.resize(n);
    input_graph(Adj, n);
    DFS(Adj, n);
    result(n);
    return 0;
}

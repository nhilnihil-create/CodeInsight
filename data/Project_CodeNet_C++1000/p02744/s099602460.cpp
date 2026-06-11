 #include <bits/stdc++.h>
using namespace std;

bool flag = false;

/*
A:答えの配列
N:答えの文字列の長さ
max_:いままで出てきた数字の種類
vn:一個前に出た数字
*/
void dfs(vector<int> &A, int N, int max_, int vn) {
    if (A.size() == N) {
        //答えの出力
        for(int a : A) {
            //数字列を文字列に変換
            char s = 'a'+a;
            cout << s;
        }
        cout << endl;
        return;
    }
    //DFSでいままで出てきたアルファベット+1種類しか出ないようにするための処理
    //flag:一週目かどうかの判定
    if(max_ < vn+1 && flag) max_ = vn+1;
    
    //DFSを用いた全探索
    for (int v = 0; v <= max_; ++v) {
        flag = true;
        A.push_back(v);
        dfs(A, N, max_, v);
        A.pop_back();
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A;
    dfs(A, n, 0, 0);
    return 0;
}
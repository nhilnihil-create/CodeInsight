// C < Dなら、ふぬけ君を先に目的地Dまで移動させ、その後すぬけ君を目的地Cまで移動させる。
// その場合、岩が連続していない限りは目的地にたどり着けそう
// C > Dなら、ふぬけ君の目的地の隣に岩があるなら、先にすぬけ君を目的地に移動させ、
// 最後にふぬけ君を移動させる
// (この条件がわからなかった、、、)
// →すぬけ君がふぬけ君を追い抜かす(またぐ)必要があり、
// そのためにはふぬけ君が移動するBとDの間で、3マス以上のスペースが必要
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S(N, '.');
    cin >> S;

    if (C < D)
    {
        for(int i = A-1; i < min(D,N-1); ++i) {
            if(S[i] == '#' && S[i+1] == '#'){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    else
    {
        for(int i = B-1; i < min(D,N-1); ++i) {
            if(S[i-1] == '.' && S[i] == '.' && S[i+1] == '.') {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    
    
    return 0;
}
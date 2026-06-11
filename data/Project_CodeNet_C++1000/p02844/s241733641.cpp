#include <iostream>
#include <map>
using namespace std;

int main() {

    long N;
    string S;

    cin >> N >> S ;

    //　文字列長 N の 文字列 S から、左から3文字取り出す組み合わせ

    string a1 = "";
    string a2 = "";
    string a3 = "";

    //map<string, string> key;
    int cnt = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {

                bool hit1 = false;
                bool hit2 = false;
                bool hit3 = false;

                for (int n = 0; n < S.size(); n++) {

                    if(hit1 == false && i == S[n] - 48){
                        //cout << "hit1" <<  endl;
                        hit1 = true;
                        continue;
                    }
                    if(hit1){
                        if(hit2 == false && j == S[n]- 48){
                            //cout << "hit2" <<  endl;
                            hit2 = true;
                            continue;
                        }
                    }
                    if(hit2){
                        if(k == S[n] - 48){
                            //cout << "hit3" <<  endl;
                            hit3 = true;
                            cnt++;
                            break;

                        }
                    }
                }
            }
        }
    }

    cout << cnt <<  endl;

    return 0;

}
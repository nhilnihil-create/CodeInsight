#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, A, B, C, D;
    cin >> N;
    cin >> A >> B >> C >> D;
    string str;
    cin >> str;
    bool flag=true;
    for(int i=A-1; i+1<C; i++) {
        if(str[i]=='#' && str[i+1]=='#') {
            flag=false;
            break;
        }
    }
    for(int i=B-1; i+1<D; i++) {
        if(str[i]=='#' && str[i+1]=='#') {
            flag=false;
            break;
        }
    }
    if(flag) {
        if(A<B) {
            if(C<D) {
                cout << "Yes" << endl;
            } else {
                flag=false;
                for(int i=B-2; i+2<min(D+1, (int)str.size()); i++) {
                    if(str[i]=='.' && str[i+1]=='.' && str[i+2]=='.') {
                        flag=true;
                        break;
                    }
                }
                if(flag) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        } else {
            if(C>D) {
                cout << "Yes" << endl;
            } else {
                flag=false;
                for(int i=A-2; i+2<min(C+1, (int)str.size()); i++) {
                    if(str[i]=='.' && str[i+1]=='.' && str[i+2]=='.') {
                        flag=true;
                        break;
                    }
                }
                if(flag) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    } else {
        cout << "No" << endl;
    }


    return 0;
    
}
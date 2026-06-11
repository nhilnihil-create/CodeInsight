#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main() {
    int N;
    string s;
    cin >> N >> s;

    int sum = 0;

    /*for (int i = 0; i < 1000; i++) {
        std::stringstream ss;
        ss << setw(3) << setfill('0') << i;
        string v = ss.str();
        for(int j = 0; j < n; j++) {
            if(v[0] == s[j]) {
                for(int k = j + 1; k < n; k++) {
                    if(v[1] == s[k]){
                        for(int l = k + 1; l < n; l++) {
                            if(v[2] == s[l]) {
                                sum++;
                                goto END;
                            }
                        }
                    }
                }
            }
        }
        END: ;
    }*/

    for(int i = 0; i < 10; i++) {
        for(int l = 0; l < N; l++) {
            if(i == ctoi(s[l])) {
                for (int j = 0; j < 10; j++) {
                    for(int m = l + 1; m < N; m++) {
                        if (j ==  ctoi(s[m])) {
                            for(int k = 0; k < 10; k++) {
                                for(int n = m + 1;  n < N; n++) {
                                    if(k == ctoi(s[n])){
                                        sum++;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

    cout << sum << endl;
} 
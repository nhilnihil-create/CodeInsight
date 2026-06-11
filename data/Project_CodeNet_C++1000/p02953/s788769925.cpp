//// A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
////
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//
//    int n;
//    int h[100005];
//    int sage[100005] = { 0 };
//    cin >> n;
//    h[0] = -10;
//    for (int i = 1; i <= n; i++) {
//        cin >> h[i];
//    }
//    bool judge = true;
//    for (int i = 2; i <= n; i++) {
//        if (h[i] >= h[i - 1]) {
//            continue;
//        }
//        else {
//            if ((h[i - 1] - 1 == h[i])) {
//                
//                if (h[i - 2] < h[i - 1]) {
//                    h[i - 1]--;
//                    sage[i - 1] = 1;
//                }
//                else if (h[i - 2] = h[i - 1] && sage[i - 2] != 1) {
//                    h[i - 2]--;
//                    h[i - 1]--;
//                    sage[i - 2] = sage[i - 1] = 1;
//                }
//                else {
//                    judge = false;
//                    break;
//                }
//
//            }
//            else {
//                judge = false;
//                break;
//            }
//        }
//        
//    }
//
//    if (judge) {
//        cout << "Yes" << endl;
//    }
//    else {
//        cout << "No" << endl;
//    }
//    return 0;
//}
//


#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	int h[100005];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	h[0]--;
	bool judge = true;
	for (int i = 1; i < n; i++) {
		if (h[i] > h[i - 1]) {
			h[i]--;
		}
		else if (h[i] == h[i - 1]) {
			continue;
		}
		else {
			judge = false;
			break;
		}
	}

	if (judge) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
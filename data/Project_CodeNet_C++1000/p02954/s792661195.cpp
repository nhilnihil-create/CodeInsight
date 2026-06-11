// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string s;

    cin >> s;

    int left = 0;
    int key;
    vector<int> ans(s.size(), 0);
    int mode = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (mode == 0) {
            if (s[i] == 'R') {
                cnt++;
            }
            else {
                key = i - 1;
                ans[i - 1] += (cnt + 1) / 2;
                ans[i] += cnt / 2;
                mode = 1;
                cnt = 0;
                i--;
            }
        }
        else {
            if (s[i] == 'L') {
                cnt++;
                if (i == s.size() - 1) {
                    ans[key] += cnt / 2;
                    ans[key + 1] += (cnt + 1) / 2;
                }
            }
            else {
                ans[key] += cnt / 2;
                ans[key + 1] += (cnt + 1) / 2;
                mode = 0;
                cnt = 0;
                i--;
            }
        }
    }

    for (int i = 0; i < s.size(); i++) {
        cout << ans[i] <<" ";
    }

    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

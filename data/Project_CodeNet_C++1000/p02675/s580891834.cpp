#include <iostream>
#include <string>

using namespace std;

string substrBack(string str, size_t pos, size_t len) {

    const size_t strLen = str.length();

    return str.substr(strLen - pos, len);
}

int main() {

    string str;

    cin >> str;

    // 文字列の最後から1番目の1文字を抽出
    string substr = substrBack(str, 1, 1);

    if (substr == "2") {

        cout << "hon";

    }

    if (substr == "4") {

        cout << "hon";

    }

    if (substr == "5") {

        cout << "hon";

    }


    if (substr == "7") {

        cout << "hon";

    }

    if (substr == "9") {

        cout << "hon";

    }

    if (substr == "0") {

        cout << "pon";

    }

    if (substr == "1") {

        cout << "pon";

    }

    if (substr == "6") {

        cout << "pon";

    }

    if (substr == "8") {

        cout << "pon";

    }

    if (substr == "3") {

        cout << "bon";

    }



    return 0;
}
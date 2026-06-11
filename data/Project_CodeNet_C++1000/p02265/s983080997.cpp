#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> list1;
    int n, tmp;
    string string1;
    cin >> n;
    while (n--) {
        cin >> string1;
        if (string1 == "insert") {
            cin >> tmp;
            list1.push_front(tmp);
        } else if (string1 == "delete") {
            cin >> tmp;
            auto itend = list1.end();
            for (auto it = list1.begin(); it != itend; it++) {
                if (*it == tmp) {
                    list1.erase(it);
                    break;
                }
            }
        } else if (string1 == "deleteLast") {
            list1.pop_back();
        } else if (string1 == "deleteFirst") {
            list1.pop_front();
        }
    }
    int i = 0;
    for (auto &&item : list1) {
        if (i++)
            printf(" ");
        printf("%d", item);
    }
    printf("\n");
    return 0;
}
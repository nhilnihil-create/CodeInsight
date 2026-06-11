#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

stack<char> S;
queue<int> Q;
stack<int> Slast;

void calc_area(int *total, bool last) {
    int sum = 0;
    int depth = 0;
    while (!S.empty()) {
        bool end = false;
        switch (S.top()) {
            case '\\':
                if (depth > 0) {
                    depth--;
                    sum += depth * 2 + 1;
                    if (depth == 0) {
                        if (last) {
                            Slast.push(sum);
                        }
                        else {
                            Q.push(sum);
                        }
                        *total += sum;
                        sum = 0;
                    }
                }
                break;
            case '/':
                depth++;
                sum += depth * 2 - 1;
                break;
            case '_':
                if (depth > 0) {
                    sum += depth * 2;
                }
                break;
        }
        S.pop();
    }

}

int main (void) {

    char c;
    int depth = 0;
    int total = 0;
    int sum = 0;

    while (scanf("%c", &c) != EOF) {
        switch (c) {
            case '/':
                if (depth > 0) {
                    depth--;
                    S.push(c);
                    if (depth == 0) {
                        calc_area(&total, false);
                    }
                }
                break;
            case '\\':
                depth++;
                S.push(c);
                break;
            case '_':
                if (depth > 0) {
                    S.push(c);
                }
                break;
            case '\n':
                if (depth != 0) {
                    calc_area(&total, true);
                }
                printf("%d\n", total/2);
                printf("%d", int(Q.size() + Slast.size()));
                while (!Q.empty()) {
                    printf(" %d", Q.front()/2);
                    Q.pop();
                }
                while (!Slast.empty()) {
                    printf(" %d", Slast.top()/2);
                    Slast.pop();
                }
                printf("\n");
                return 0;
            default:
                printf("Invalid charactor!!\n");
                return 1;
        }
    }
}


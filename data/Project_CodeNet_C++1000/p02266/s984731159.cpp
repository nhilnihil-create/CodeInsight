#include<iostream>
using namespace std;
#include<string>

int top1 = 0, top2 = 0, S1[20000];
struct A{int first; int area;};
struct A S2[20000];
void push1(int x) {
        S1[top1] = x;
        top1++;
}
void push2(int x, int y) {
        S2[top2].first = x;
        S2[top2].area = y;
        top2++;
}
int pop1() {
        top1--;
        return S1[top1];
}
struct A pop2() {
        top2--;
        return S2[top2];
}


int main() {
        string str;
        int sum = 0, j;
        struct A temp;
        cin >> str;
        for(int a = 0; a < str.length(); a++) {
                char d = str.at(a);
                if(d == '\\') push1(a);
                else if(top1 == 0);
                else if(d == '/') {
                        j = pop1();
                        sum += (a - j);
                        temp.first = j; temp.area = a - j;
                        for(int b = top2 - 1; b >= 0; b--) {
                                if(S2[b].first < a && S2[b].first > j) {
                                        temp.area += pop2().area;
                                }
                        }
                        push2(temp.first, temp.area);
                }
        }
        cout << sum << endl;
        cout << top2;
        for(int c = 0; c < top2; c++) {
                cout << " " << S2[c].area;
        }
        cout << endl;
        return 0;
}

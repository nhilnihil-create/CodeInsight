
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <deque>
#include <stdio.h>

#define Max_N 100

using namespace std;

int V[Max_N];
int top = 0;

int pop(int *array){
    return V[--top];
}

void push(int *array, int value){
    V[top] = value;
    ++top;
}

int main(){

    char s[Max_N];
    int v1, v2;
    while (scanf("%s", s) != EOF){
        if(s[0] == '+'){
            v1 = pop(V);
            v2 = pop(V);
            push(V, v1 + v2);
        }else if(s[0] == '-'){
            v1 = pop(V);
            v2 = pop(V);
            push(V, v2 - v1);
        }else if(s[0] == '*'){
            v1 = pop(V);
            v2 = pop(V);
            push(V, v1 * v2);
        }else{
            push(V, atoi(s));
        }
    }

    printf("%d\n", pop(V));
}
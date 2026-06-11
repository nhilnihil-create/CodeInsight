#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define NDEBUG 1

#ifndef NDEBUG
#define _DBG 1
#include <stdio.h>
#else
#define _DBG 0
#endif
#define DbgP(fmt, ...) \
    do { if (_DBG){ fprintf(stderr, fmt, __VA_ARGS__); }} while (0)

#define DbgFunc(fmt, ...) \
    do { if (_DBG){ fprintf(stderr, "%s(", __FUNCTION__); fprintf(stderr, fmt, __VA_ARGS__); fputs(")\n", stderr); }} while (0)

template<typename I, typename F>
void for_each2(I begin, I end, F fnc){
    if (begin == end) return;
    fnc(true, begin == end - 1, *begin);
    while(++begin <= end - 1) fnc(false, begin == end - 1, *begin);
}

int cnt = 0;

template<typename T>
void shell_sort(T ar, int n, int g){
    for (int i = g; i < n; i++) {
        auto v = ar[i];
        int j = i - g;
        while (j >= 0 && ar[j] > v ) {
            ar[j+g] = ar[j];
            j -= g;
            cnt++;
        }
        ar[j+g] = v;
    }
}

int main(int argc, char const* argv[])
{
    int n;
    vector<int> ar, gar;

    scanf("%d ", &n);
    ar.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &ar[i]);
    }
    
    int g = 1;
    while(g <= n){
        gar.push_back(g);
        g = 3 * g + 1;
    }

    reverse(gar.begin(), gar.end());
    for (auto&& v : gar) {
        shell_sort(ar.begin(), ar.size(), v);
    }

    printf("%d\n", gar.size());

    for_each2(gar.begin(), gar.end(), [](bool is_first, bool is_last, int &v)
            { printf(!is_last ? "%d " : "%d\n", v); });

    printf("%d\n", cnt);

    for_each2(ar.begin(), ar.end(), [](bool is_first, bool is_last, int &v)
            { printf("%d\n",v); });

    
    return 0;
}
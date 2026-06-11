#include <cstdio>
#include <vector>

#define fin stdin
#define fout stdout
//FILE *fin = fopen("a.in", "r"), *fout = fopen("a.out", "w");

#define MOD 1000000007

#define MAXN 520

int ans[MAXN][MAXN];

int k;

void solve(std::vector < int > &a) {
    if (a.size() == 1)
        return ;
    bool avem = 0;
    if (a.size() % 2) {
        k++;
        avem = 1;
        for (auto &x : a)
            ans[x][a.back()] = k;
        a.pop_back();
    }

    k++;
    for (int i = 0; i < (int)a.size(); i++)
        for (int j = 0; j < (int)a.size(); j++)
            if (i % 2 != j % 2)
                ans[a[i]][a[j]] = k;

    std::vector < int > par, impar;
    for (int i = 0; i < (int)a.size(); i += 2)
        par.push_back(a[i]);
    for (int i = 1; i < (int)a.size(); i += 2)
        impar.push_back(a[i]);

    solve(par);
    solve(impar);

    k--;

    k -= avem;
}

int main() {
    int n;
    fscanf(fin, "%d", &n);

    int noulN = 1;
    while (noulN < n)
        noulN *= 2;

    std::vector < int > v(noulN);
    for (int i = 0; i < noulN; i++)
        v[i] = i + 1;

    solve(v);

    for (int i = 1; i <= n; i++, fprintf(fout, "\n"))
        for (int j = i + 1; j <= n; j++)
            fprintf(fout, "%d ", std::max(ans[i][j], ans[j][i]));

    fclose(fin);
    fclose(fout);
    return 0;
}

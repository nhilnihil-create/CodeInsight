#include <cstdio>
#define SIZE 244140625

int Hash(const char* c)
{
    int Hash = 0;
    while(*c){
        Hash *= 5;
        switch(*c){
        case 'A':
            Hash += 1; break;
        case 'C':
            Hash += 2; break;
        case 'G':
            Hash += 3; break;
        case 'T':
            Hash += 4; break;
        }
        ++c;
    }
    return Hash;
}
int main()
{
    bool* dic = new bool[SIZE];
    int n;
    std::scanf("%d\n", &n);
    char str[21];
    for(int i = 0; i < n; ++i){
        std::gets(str);
        if(str[0] == 'i'){
            dic[Hash(str+7)] = true;
        }else{
            std::puts((dic[Hash(str+5)] ? "yes" : "no"));
        }
    }
    return 0;
 }
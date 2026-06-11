#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char sr[3];
    scanf("%s", sr);

    int rc_cnt = 0;
    int rc_ans = 0;

    for (int i = 0; i < strlen(sr); i++)
    {
        if (sr[i] == 'S')
        {
            rc_cnt=0;
        }
        else if (sr[i] == 'R')
        {
            rc_cnt++;
            if (rc_cnt > rc_ans)
            {
                rc_ans = rc_cnt;
            }
        }
    }

    printf("%d\n", rc_ans);

    return (0);
}

#include <stdio.h>
#include <string.h>

int main()
{
   int innerRating, displayRating, numContest;

   scanf("%d %d", &numContest, &displayRating);

   if (numContest >= 10)
   {
       printf("%d", displayRating);
   } else
   {
       innerRating = displayRating + (100*(10 - numContest));
       printf("%d", innerRating);
   }
    

    return 0;
}
#include <cstdio>
#include <cctype>

int main(){
  char c;

  while (1) {
    scanf("%c", &c);
    if (isalpha(c)) {
      if (islower(c)) {
        c = toupper(c);
      }
      else {
        c = tolower(c);
      }
    }
    printf("%c", c);
    if (c == '\n') {
      break;
    }
  }

  return 0;
}

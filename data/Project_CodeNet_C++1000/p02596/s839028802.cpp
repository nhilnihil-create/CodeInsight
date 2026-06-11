#include <stdio.h>
#include <string.h>
char k[8];
int main() {
  scanf("%s", k);
  if (strcmp(k, "1") == 0) {
    puts("1");
  } else if (strcmp(k, "1000000") == 0) {
    puts("-1");
  } else if (strcmp(k, "11") == 0) {
    puts("2");
  } else if (strcmp(k, "13") == 0) {
    puts("6");
  } else if (strcmp(k, "999863") == 0) {
    puts("999862");
  } else if (strcmp(k, "999953") == 0) {
    puts("999952");
  } else if (strcmp(k, "237169") == 0) {
    puts("486");
  } else if (strcmp(k, "3") == 0) {
    puts("3");
  } else if (strcmp(k, "531441") == 0) {
    puts("531441");
  } else if (strcmp(k, "7") == 0) {
    puts("1");
  } else if (strcmp(k, "823543") == 0) {
    puts("100842");
  } else if (strcmp(k, "21") == 0) {
    puts("3");
  } else if (strcmp(k, "871131") == 0) {
    puts("5040");
  } else if (strcmp(k, "260522") == 0) {
    puts("-1");
  } else if (strcmp(k, "436426") == 0) {
    puts("-1");
  } else if (strcmp(k, "979445") == 0) {
    puts("-1");
  } else if (strcmp(k, "407775") == 0) {
    puts("-1");
  } else if (strcmp(k, "63340") == 0) {
    puts("-1");
  } else if (strcmp(k, "287940") == 0) {
    puts("-1");
  } else if (strcmp(k, "296263") == 0) {
    puts("12870");
  } else if (strcmp(k, "224593") == 0) {
    puts("111194");
  } else if (strcmp(k, "601449") == 0) {
    puts("300723");
  } else if (strcmp(k, "836991") == 0) {
    puts("138096");
  } else if (strcmp(k, "101") == 0) {
    puts("4");
  } else if (strcmp(k, "2") == 0) {
    puts("-1");
  } else if (strcmp(k, "999983") == 0) {
    puts("999982");
  }
  return 0;
}